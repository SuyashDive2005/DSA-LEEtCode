/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfSquares = function(nums) {
    let size=nums.length;
    let ans=0;

    for(let i=1;i<=size;i++){
        if(size%i==0){
            ans+=(nums[i-1]*nums[i-1]);
        }
    }
    return ans;
};