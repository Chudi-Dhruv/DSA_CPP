class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        n = len(nums1)
        m = len(nums2)
        final_ans = []
        for i in range(n):
            ans = -1
            for j in range(m):
                if(nums2[j]==nums1[i]):
                    while(j<m):
                        print(nums1[i])
                        if(nums2[j]<=nums1[i]):
                            j+=1
                        else:
                            break
                    if(j<m and nums2[j]>nums1[i]):
                        ans = nums2[j]
            final_ans.append(ans)
        return final_ans

        
