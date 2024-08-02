def canJump():
    N = int(input())
    nums = input().split(' ')
    for i in range(len(nums)):
        nums[i] = int(nums[i])
    def dfs(ind, memo):
        if ind in memo:
            return memo[ind]
        if ind >= len(nums)-1:
            return True 
        if nums[ind] == 0:
            return False
        for steps in range(nums[ind], 0, -1):
            goTo = ind + steps
            if dfs(goTo, memo):
                memo[ind] = True
                return True
        memo[ind] = False
        return False
    return dfs(0, {})
print(canJump())