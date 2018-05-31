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
    string again;    //반복되는 문자열
    int start, end;    //반복 문자열의 시작, 끝 위치
    char num;    //반복 횟수 문자
    int againNum;    //반복 횟수
    int temp;    //문자열에서 반복 횟수의 위치
    int pair = 0;
    
    while (s.find('(') != -1) {
        //반복되는 문자열 찾아서 삽입하기
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
        s.erase(start - 1, 1);    //'('지우기
        s.erase(end, 1);    //')'지우기
        s.erase(temp - 2, 1);    //'^'지우기
        s.erase(end, 1);    //숫자 지우기
        for (int j = 0; j < againNum - 1; j++) {
            s.insert(start-1, again);    //반복된 문자열 삽입
        }
    }
}

void String::same(string s1, string s2) {
    if (s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int N;    //비교할 문자열 갯수
    cin >> N;
    
    String string(N);
}

