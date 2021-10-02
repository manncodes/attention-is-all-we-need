#include <iostream>
#include <string>
using namespace std;
class key {
   public:
      string k;
   key(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   string encryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A';
         j = (j + 1) % k.length();
      }
      return output;
   }
   string decryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';
         j = (j + 1) % k.length();
      }
      return output;
   }
};
int main() {
    printf("18BCE0420\nEnter Key\n");
    string s;
cin>>s;
   key v(s);
   string text ="AGRAWALKUNALDHARMENDRA";
   string encrypt = v.encryption(text);
   string decrypt = v.decryption(encrypt);
   cout << "Original Message: "<<text<< endl;
   cout << "Encrypted Message: " << encrypt << endl;
   cout << "Decrypted Message: " << decrypt << endl;
}
