#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    for(int i=0; i<n; ++i){
        int sum = arr1[i] | arr2[i];
        for(int j=n; sum > 0 || j > 0; --j){
            answer[i] = (sum % 2 ? "#" : " ") + answer[i];
            sum /= 2;
        }
    }
    
    return answer;
}