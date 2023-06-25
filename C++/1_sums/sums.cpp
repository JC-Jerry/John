# include <vector>
# include <iostream>
using namespace std;
class solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            int i,j;
            vector<int> ret_val ={0, 0};
            for(i=0; i<nums.size(); i++)
            {
                for (j = i+1; j < nums.size(); j++)
                {
                    // if((nums[i]==target-nums[j]))
                    if((target==nums[i]+nums[j]))
                    {
                        cout<<nums[i] << " "<< nums[j] <<endl; 
                        vector<int> ret_val ={nums[i], nums[j]};
                        // return ret_val;
                        return {nums[i], nums[j]};
                    }
                }
            }
            return ret_val;
        }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    
    int target = 9;
    solution s;
    auto out = s.twoSum(nums, 9);
    cout<< out[0]<<" " << out[1] << endl; 
}

// nums.assign();