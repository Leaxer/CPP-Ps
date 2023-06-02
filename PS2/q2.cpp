#include <iostream>

using namespace std;

const int MAX_LENGTH = 20;

void reverse(int a[], int len);
void add(int a[], int b[], int len, int sumArr[]);
int ArrLength(char num[]);

int main(){
    char num1[MAX_LENGTH],num2[MAX_LENGTH];
    int num1_length,num2_length,finish = 1;
    int sum[MAX_LENGTH];
    int num1Arr[MAX_LENGTH] = {0},num2Arr[MAX_LENGTH] = {0};
    while(finish == 1) {
        cout << "Please enter an integer, 20 digits or less" << endl;
        cin>>num1;
        cout << "Please enter an integer, 20 digits or less" << endl;
        cin>>num2;
        num1_length = ArrLength(num1);
        num2_length = ArrLength(num2);
        if(num1_length > MAX_LENGTH || num2_length > MAX_LENGTH) {
            cout << "Your array should be less than " << MAX_LENGTH;
            finish = 0;
        }else {
            for (int i = 0; i < num1_length; i++) {
                num1Arr[i] = num1[i] - 48;
            }
            for (int i = 0; i < num2_length; i++) {
                num2Arr[i] = num2[i] - 48;
            }
            reverse(num1Arr,num1_length);
            reverse(num2Arr,num2_length);

            if(num1_length > num2_length) {
                add(num1Arr,num2Arr,num1_length,sum);
            }else {
                add(num1Arr,num2Arr,num2_length,sum);
            }
            cout << "To do another addition, enter 1" << endl;
            cin>>finish;
        }
    }
    return 0;
}

void reverse(int a[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }
}

void add(int a[], int b[], int len, int sumArr[]) {
    int flow = 0;
    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + flow;
        sumArr[i] = sum % 10;
        flow = sum / 10;
    }
    if (flow > 0) {
        sumArr[len] = flow;
        ++len;
    }
    if(len > MAX_LENGTH) {
        cout << "integer overflow!" << endl;
        return;
    }
    reverse(sumArr, len);
    cout << "Result: ";
    for(int i = 0;i < len;++i) {
        cout << sumArr[i];
    }
    cout << endl;
}

int ArrLength(char num[]) {
    int i = 0;
    while(num[i] != '\0') {
        ++i;
    }
    return i;
}