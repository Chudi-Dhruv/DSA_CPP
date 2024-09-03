def sort_meet(meetings):
        for i in range(len(meetings)):
            for j in range(i+1, len(meetings)):
                if(meetings[i][0]>meetings[j][0]):
                    temp = meetings[i]
                    meetings[i] = meetings[j]
                    meetings[j] = temp
        return meetings

class Solution(object):


    def countDays(self, days, meetings):
        meetings.sort()
        # meetings = sort_meet(meetings)
        ans = 0
        print(meetings)
        n = len(meetings)
        if ((meetings[0][0] - 1) > 0):
            ans+= meetings[0][0] - 1
        last_meeting = meetings[0][1]
        for i in range(n-1):
            if((meetings[i+1][0]-last_meeting-1 )>0):
                ans+=meetings[i+1][0]-last_meeting-1
                # print(ans, 'at index', i)
            last_meeting = max(last_meeting, meetings[i+1][1])
        if (days - last_meeting > 0):
            ans+= days - last_meeting
        return ans
        
