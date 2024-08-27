#include <queue>
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                 
    vector<long long> ans;
    queue<long long> neg_num_arr;
    long long int i=0,j=0;
    while(j<N){
        if (A[j]<0){
            neg_num_arr.push(A[j]);
        }
        if(j-i+1 == K){
            if(neg_num_arr.size()!=0){
                ans.push_back(neg_num_arr.front());
            }
            else{
                ans.push_back(0);
            }
            if(A[i]==neg_num_arr.front()){
                neg_num_arr.pop();
            }
            i++; 
        }
        j++;
    }
    return ans;
