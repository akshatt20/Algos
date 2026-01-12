class Solution {
public:
vector<int> nextSmaller(vector<int>& heights)
{
    int n=heights.size();
    vector<int> next(n);
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr)
        {
            st.pop();
        }
        next[i]=st.top();
        st.push(i);
    }
    return next;
}

vector<int> prevSmaller(vector<int>& heights)
{
    int n=heights.size();
    vector<int> prev(n);
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++)
    {
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr)
        {
            st.pop();
        }
        prev[i]=st.top();
        st.push(i);
    }
    return prev;
}

    int largestRectangleArea(vector<int>& heights) {
     int n=heights.size();
     vector<int> next=nextSmaller(heights);
     vector<int> prev=prevSmaller(heights);  
     int ans=0;
     for(int i=0;i<n;i++)
     {
        int len=heights[i];
        if(next[i]==-1)next[i]=n;
        int w=next[i]-prev[i]-1;
        ans=max(ans,len*w);
     }
     return ans;

    }
};