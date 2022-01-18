//
//  rsa.cpp
//  react-native-jsi-cryptography
//
//  Created by Julian Kobrynski on 18/01/2022.
//

#import "rsa.h"
#include <iostream>
#include <math.h>

using namespace std;

namespace rsa {
    void runExample() {
        cout << "****Running example" << endl;
    }

    int gcd(int a, int b) {
       int t;
       while(1) {
          t= a%b;
          if(t==0)
          return b;
          a = b;
          b= t;
       }
    }

    double encryptMessage(double message) {
        double p = 13;
        double q = 11;
        double n=p*q;
        double track;
        double phi= (p-1)*(q-1);
        double e=7;
        
        while(e<phi) {
           track = gcd(e,phi);
           if(track==1)
              break;
           else
              e++;
        }
        
        double c = pow(message, e); //encrypt the message
        c=fmod(c,n);
        
        return c;
    }

    double decryptMessage(double encrypted) {
        double p = 13;
        double q = 11;
        double n=p*q;//calculate n
        double track;
        double phi= (p-1)*(q-1);//calculate phi
        //public key
        //e stands for encrypt
        double e=7;
        //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
        while(e<phi) {
           track = gcd(e,phi);
           if(track==1)
              break;
           else
              e++;
        }
        //private key
        //d stands for decrypt
        //choosing d such that it satisfies d*e = 1 mod phi
        double d1=1/e;
        double d=fmod(d1,phi);
        double message = 9;
        double c = pow(message,e); //encrypt the message
        double m = pow(c,d);
        c=fmod(c,n);
        m=fmod(m,n);
        
        return m;
    }
}
