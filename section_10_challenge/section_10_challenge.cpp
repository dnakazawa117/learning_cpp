#include <iostream>
#include <string>

using namespace std; 

static void encrypt_secret_message(string* secret_message, string alphabet, string cipher); 
static void decrypt_secret_message(string* secret_message, string alphabet, string cipher);

int main() 
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string cipher   {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"}; 

    cout << "Enter your secret message: "; 
    string secret_message {}; 
    getline(cin, secret_message); 

    encrypt_secret_message(&secret_message, alphabet, cipher); 
    decrypt_secret_message(&secret_message, alphabet, cipher); 

    return 0;
}

static void encrypt_secret_message(string* secret_message, string alphabet, string cipher)
{
    cout << "Encrypting message..." << endl; 
    
    size_t position = 0; 
    for (char character : (*secret_message))
    {
        if (isalpha(character))
        {
            (*secret_message).at(position) = cipher.at(alphabet.find(character)); 
        }
        
        position++; 
    }

    cout << "Your encrypted message is: " << (*secret_message) << endl; 

    return; 
}

static void decrypt_secret_message(string* secret_message, string alphabet, string cipher)
{
    cout << "Decrypting message..." << endl; 

    size_t position = 0; 
    for (char character : (*secret_message))
    {
        if (isalpha(character))
        {
            (*secret_message).at(position) = alphabet.at(cipher.find(character)); 
        }
        
        position++; 
    }

    cout << "Your decrypted message is: " << (*secret_message) << endl; 

    return; 
}