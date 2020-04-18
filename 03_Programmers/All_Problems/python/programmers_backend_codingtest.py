## 2번
def solution(office, r, c, move):
    answer = 0
    N = len(office)
    M = len(office[0])
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    queue = []

    queue.append([r,c])
    answer += office[r][c]
    dir = 3
    for cmd in move:
        cur = queue.pop(0)

        if cmd == "go":
            next = [(cur[0] + dy[dir]), cur[1] + dx[dir]]
        elif cmd=="right":
            dir = (dir+1)%4
        elif cmd=="left":
            dir = (dir+3)%4

        if next[0]>=0 and next[0]<N and next[1]>=0 and next[1]<M:
            if office[next[0]][next[1]]>-1:
                answer+=office[next[0]][next[1]]
                office[next[0]][next[1]] = 0
            queue.append(next)
        else: queue.append(cur)
    return answer

input_office = [[5,-1,4],[6,3,-1],[2,-1,1]]
input_r = 1
input_c = 0
input_move = ["go","go","right","go","right","go","left","go"]
print(solution(input_office, input_r, input_c, input_move))

# 5 -1 4 
# 6 3 -1
# 2 -1 1




## 1번
# def solution(p,s):
#     answer = 0
#     for i in range(len(p)):
#         x = int(p[i])
#         y = int(s[i])

#         if(x>y):
#             if(x-y<y+10-x):
#                 answer += x-y
#             else:
#                 answer += y+10-x
#         else:
#             if(y-x<x+10-y):
#                 answer += y-x
#             else:
#                 answer += x+10-y
        
#     return answer

# input_p = "82195"
# input_s = "64723"
# print(solution(input_p, input_s))

# # 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
# # 0 1 2 3 4 5 6 7 8 9  0  1  2  3  4  5  6  7  8  9 
# #             x   y                      x      
# #             y   x                      y     