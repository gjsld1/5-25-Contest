//
//  2.cpp
//  Contest
//
//  Created by 신예지 on 2018. 5. 30..
//  Copyright © 2018년 신예지. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class String {
    int n;    //2*N
    string *s;
public:
    String(int N) {
        n = 2 * N;
        s = new string[n];
        getString();
        
        for (int i = 0; i < n; i++) changeFull(s[i]);
        
        for (int i = 0; i < N; i++) {
            same(s[2 * i], s[2 * i + 1]);
        }
    }
    
    void getString();
    void changeFull(string s);
    void same(string s1, string s2);
};

void String::getString() {
    for (int i = 0; i < n; i++)
        cin >> s[i];
}

void String::changeFull(string s) {
    string again;    //π›∫πµ«¥¬ πÆ¿⁄ø≠
    int start, end;    //π›∫πµ«¥¬ πÆ¿⁄ø≠¿« Ω√¿€∞˙ ≥° ¿ßƒ°
    char num;    //π›∫π »Ωºˆ char
    int againNum;    //π›∫π »Ωºˆ int
    int temp;    //π›∫π »Ωºˆ¿« Ω∫∆Æ∏µø°º≠¿« ¿ßƒ°
    int pair = 0;
    
    while (s.find('(') != -1) {
        //π›∫πµ«¥¬ πÆ¿⁄ø≠¿« Ω√¿€ ¿ßƒ°øÕ ≥° ¿ßƒ° √£±‚
        if (s.find('(')) {
            start = s.find('(') + 1;
            pair++;
        }
        if (s.find(')')) {
            end = s.find(')') - 1;
            pair++;
        }
        if (s.find('^')) {
            temp = s.find('^') + 1;
            pair++;
            num = s.at(temp);
            againNum = num - '0';
        }
        if (pair % 3 != 0) {
            break;
            cout << "NO" << endl;
        }
        again = s.substr(start, end - start + 1);
        s.erase(start - 1, 1);    //'('ªË¡¶
        s.erase(end, 1);    //')'ªË¡¶
        s.erase(temp - 2, 1);    //'^'ªË¡¶
        s.erase(end, 1);    //º˝¿⁄ ªË¡¶
        for (int j = 0; j < againNum - 1; j++) {
            s.insert(start-1, again);    //π›∫ππÆ¿⁄ µ°∫Ÿ¿Ã±‚
        }
    }
}

void String::same(string s1, string s2) {
    if (s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int N;    //∫Ò±≥«“ Ω∫∆Æ∏µ Ω÷¿« ∞πºˆ
    cin >> N;
    
    String string(N);
}

