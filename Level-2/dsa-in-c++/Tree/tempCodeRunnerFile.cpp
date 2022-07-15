   vector<vector<int>>ans;
    if(root == nullptr)
        return ans;
    queue<qTriplet> q;
    q.push(qTriplet(root,0,1));
    int lh = 0;
    int rh = 0;
    unordered_map<int, priority_queue<qTriplet,vector<qTriplet>,myComp>> hm;
    while(q.size() > 0)
    {
        qTriplet remNode = q.front();
        q.pop();
        if(remNode.h < lh)
            lh = remNode.h;
        if(remNode.h > rh)
            rh = remNode.h;
        
        if(hm.find(remNode.h) == hm.end())
        {
            priority_queue<qTriplet, vector<qTriplet>,myComp>temp;
            hm.insert(make_pair(remNode.h,temp));
            hm[remNode.h].push(remNode);
        }
        else{
            hm[remNode.h].push(remNode);
        }
        if(remNode.node->left != nullptr)
        {
            q.push(qTriplet(remNode.node->left,remNode.h - 1, remNode.v + 1));
        }
        if(remNode.node->right != nullptr)
        {
            q.push(qTriplet(remNode.node->right, remNode.h + 1, remNode.v + 1));
        }
    }
    cout<<"lh: "<<lh<<" rh: "<<rh<<endl;
    for(int i = lh; i <= rh; i++)
    {
        vector<int>temp;
        auto pq = hm[i];
        while(pq.size() > 0)
        {
            auto  x = pq.top();
            pq.pop();
            temp.push_back(x.node->data);
        }
        ans.push_back(temp);
    }
    return ans;