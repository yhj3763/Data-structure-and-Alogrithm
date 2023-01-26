//for문을 중첩한 풀이
public:
vector<int> twoSum(vector<int>& nums, int target) {
      
    vector<int> ans;

    for(int i = 0; i<nums.size();i++){
       for(int j = i + 1; j<nums.size();j++){
           if(nums[i] + nums[j] == target){
               ans.push_back(i);
               ans.push_back(j);
           }
       }
   }

   return ans;
}

//자료구조 unordered_map을 이용한 풀이
public:
vector<int> twoSum(vector<int>& nums, int target) {
      
    unordered_map<int, int> num_map;
    vector<int> ans;
 
    for(int i = 0; i<nums.size();i++){
        num_map[nums[i]] = i;
    }

    for(int i = 0; i<nums.size();i++){
        if(num_map.find(target-nums[i])!= num_map.end()&& i!= num_map[target-nums[i]]){
            ans.push_back(i);
            ans.push_back(num_map[target-nums[i]]);
            return ans;
        }
    }

    return ans;
}
