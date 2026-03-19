class Solution {
public:
    bool isPerfectSquare(int num) {
        int root=sqrt(num);
        if(root*root == num){
            return true;
        }else return false;
    }
};