class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        
        for(auto task: tasks){
            mp[task]++;
        }
        
        priority_queue<int> pq;
        
        for(auto task: mp){
            pq.push(task.second);
        }
        
        int result = 0;
        
        while(!pq.empty()){
            vector<int> temp;
            int time=0;
            
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto t: temp){
                if(t) pq.push(t);
            }
            result += pq.empty()? time : n+1;
        }
        return result;
    }
};