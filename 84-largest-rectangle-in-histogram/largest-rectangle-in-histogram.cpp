class Solution {
private:    
    vector<int> nextSmallerElementIndex(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>stack;
    stack.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr=arr[i]; 
        while(stack.top()!=-1 && arr[stack.top()]>=curr){
            stack.pop();
        }
        ans[i]=stack.top();
        stack.push(i);
        
    }
    return ans;

}

    vector<int> prevSmallerElementIndex(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>stack;
    stack.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int curr=arr[i]; 
        while(stack.top()!=-1  && arr[stack.top()]>=curr){
            stack.pop();
        }
        ans[i]=stack.top();
        stack.push(i);
        
    }
    return ans;

}

public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextSmallerElementIndex(heights, n);

        vector<int>prev(n);
        prev = prevSmallerElementIndex(heights, n);

        int area=INT_MIN;
        for(int i=0; i<n; i++){
            int length =heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int breadth = next[i]- prev[i] -1;
            
            int newArea= length*breadth;
            area=max(area,newArea);

        }
        return area;
    }
};