#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;
vector<int> twoSumBruteForce(const vector<int>&nums,int target){
    vector<int> nms;
    int n = nums.size(); 

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n; j++) {
            if (nums[j]+ nums[i]==target) {
                nms.push_back(i);
                nms.push_back(j);
                return nms;
                //nms.push_back(j);
                
            }
        }
        //cout << numbers[i] << " apparaît " << count << " fois." << endl;
    }
    return nms;
}
vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    vector<int> nms;

    for(int i=0;i<nums.size();i++){
        umap[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (umap.find(complement) != umap.end()) {
            nms.push_back(i); 
            nms.push_back(umap[complement]); 
                           
            return nms;
        }
    }

    return nms;
}
int main(){
    vector<int>nums={2,7,11,15};
    int target=9;

    vector<int> indicesBruteForce=twoSumBruteForce(nums,target);
    cout<<"BruteForceSolution:["<<indicesBruteForce[0]<<","<<indicesBruteForce[1]<<"]"<<endl;
    vector<int> indicesOptimal=twoSumOptimal(nums,target);
    cout<<"OptimalSolution:["<<endl;
    cout<<indicesOptimal[0]<<", \n"<<indicesOptimal[1]<<"] \n"<<endl;
    return 0;
}
