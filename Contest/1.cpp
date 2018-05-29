//
//  main.cpp
//  Contest
//
//  Created by 신예지 on 2018. 5. 29..
//  Copyright © 2018년 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

class Prime {
    int *prime = new int[100];
public:
    Prime(int N) {
        createPrime();
    }
    
    //Pn+1=Pn*Pn-1*Pn-2*...*P1+1 규칙을 갖는 소수
    void createPrime() {
        prime[0] = 2;    //p1=2
        
        //곱셉을 위해 1로 초기화
        for (int i = 1; i <= 100; i++)
            prime[i] = 1;
        
        //i번째 prime 구하기
        for (int i = 1; i <= 100; i++) {
            //1부터 i-1까지의 곱
            for (int j = 0; j < i; j++) {
                prime[i] *= prime[j];
            }
            //+1
            prime[i] += 1;
        }
    }
    
    //입력받은 N의 prime에서의 위치 구하기
    int position(int N) {
        int p;
        for (p = 0; p < 100; p++) {
            if (prime[p] > N) break;
        }
        return p;    //N보다 작은 소수 개수
    }
};

int main() {
    int N;    //입력받을 정수
    cout << "N을 입력하세요 : ";
    cin >> N;
    
    if (N < 2) {
        cout << "0" << endl;
        return 0;
    }
    
    Prime p(N);
    cout << p.position(N) << endl;
}
