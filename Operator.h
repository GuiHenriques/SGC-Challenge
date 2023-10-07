#include <libcryptosec/certificate/CertificateBuilder.h>
#include <libcryptosec/certificate/Certificate.h>
#include <libcryptosec/certificate/RDNSequence.h>
#include <libcryptosec/BigInteger.h>
#include <libcryptosec/ByteArray.h>
#include <libcryptosec/DateTime.h>
#include <libcryptosec/MessageDigest.h>
#include <libcryptosec/RSAKeyPair.h>
#include <libcryptosec/Signer.h>

class Operator
{
private:
    // RSA Key Pair
    RSAKeyPair keyPair = RSAKeyPair(2048);
    PrivateKey *privateKey;
    PublicKey *publicKey;
    
    // certificate
    CertificateBuilder builder;
    Certificate *certificate;
    BigInteger serialNumber;
   
    // signature
    ByteArray signature;
   
    
public:
    Operator(long i)
    {
        // generate the key pair
        this->privateKey = keyPair.getPrivateKey();
        this->publicKey = keyPair.getPublicKey();

        
        // build the certificate
        builder.setPublicKey(*publicKey);
        
        this->serialNumber = BigInteger(i);
        builder.setSerialNumber(serialNumber);

        DateTime notBefore, notAfter;
        notBefore.addMinutes(-1);
        notAfter.addYears(1);
        builder.setNotAfter(notAfter);
        builder.setNotBefore(notBefore);

        RDNSequence subject;
        subject.addEntry(RDNSequence::COUNTRY, "BR");
        subject.addEntry(RDNSequence::STATE_OR_PROVINCE, "Santa Catarina");
        subject.addEntry(RDNSequence::LOCALITY, "Florianopolis");
        subject.addEntry(RDNSequence::ORGANIZATION, "UFSC");
        subject.addEntry(RDNSequence::ORGANIZATION_UNIT, "LabSec");
        subject.addEntry(RDNSequence::COMMON_NAME, "Operator " + std::to_string(i));

        builder.setSubject(subject);

        certificate = builder.sign(*privateKey, MessageDigest::Algorithm::SHA256);
        
    }

    ByteArray getSignature()
    {
        return this->signature;
    }

    void setSignature(ByteArray &signature)
    {
        this->signature = signature;
    }

    ByteArray sign(ByteArray &data)
    {
        ByteArray signature = Signer::sign(*privateKey, data, MessageDigest::Algorithm::SHA256);
        setSignature(signature);
        return signature;
    }

    bool verify(ByteArray &hash)
    {
        ByteArray signature = getSignature();
        PublicKey *certificatePublicKey = certificate->getPublicKey();
        return Signer::verify(*certificatePublicKey, signature, hash, MessageDigest::Algorithm::SHA256);
    }
};