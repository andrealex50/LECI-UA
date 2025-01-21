from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization


def rsa_key():
    key_length = 0
    while (key_length not in [1024, 2048, 3072, 4096]):
        key_length = int(input("Key Length (1024, 2048, 3072 or 4096): "))       


    private_key_filename = input("Enter filename for the private key (e.g., private_key.pem): ")
    public_key_filename = input("Enter filename for the public key (e.g., public_key.pem): ")

    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=key_length,
    )

    # Save the private key in PEM format
    with open(private_key_filename, "wb") as private_file:
        private_pem = private_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.TraditionalOpenSSL,
            encryption_algorithm=serialization.NoEncryption()
        )
        private_file.write(private_pem)

    # Generate and save the public key in PEM format
    public_key = private_key.public_key()
    with open(public_key_filename, "wb") as public_file:
        public_pem = public_key.public_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PublicFormat.SubjectPublicKeyInfo
        )
        public_file.write(public_pem)

rsa_key()