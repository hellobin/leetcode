class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        struct paire
        {
            int value;
            int index;
            paire(int v,int i)
                    :value(v),index(i)
            {

            }
        };
        vector<int> res;
        vector<paire*> container;
        for(int i = 0;i<nums.size();++i)
        {
            paire *t= new paire(nums[i],i);
            container.push_back(t);
        }
        sort(container.begin(),container.end(),[](paire *l,paire *r){
            return l->value<r->value;
        });
        for(auto it = container.begin(),post = --container.end();it!=post;)
        {
            int temp = (*it)->value+(*post)->value;
            if(temp<target)
            {
                ++it;
                continue;
            }
            else if(temp == target)
            {
                res.push_back((*it)->index);
                res.push_back((*post)->index);
                break;
            }
            else
            {
                --post;
            }

        }
        if(res.size()>=2)
        {
            if(res[0]>res[1])
            {
                int t = res[0];
                res[0] = res[1];
                res[1] = t;
            }
        }
        for(auto v:container)
        {
            delete v;
        }
        return res;
    }
};