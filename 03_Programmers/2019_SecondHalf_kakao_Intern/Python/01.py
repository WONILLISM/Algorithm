def solution(board, moves):
    answer = 0
    stack =[]
    for i in moves:
        for j in range(len(board)):
            tmp = board[j][i-1]
            board[j][i-1] = 0
            top = len(stack)
            if(tmp):
                print(tmp)
                chk = False
                if(top>0):
                    print(stack)
                    if(stack[top-1]==tmp):
                        stack.pop(len(stack)-1)
                        chk = True
                        answer+=2
                if(chk==False):stack.append(tmp)
                break
    return answer

input_board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
input_moves = [1,5,3,5,1,2,1,4]
print(solution(input_board, input_moves))
