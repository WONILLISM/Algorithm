def solution(board, moves):
    answer = 0
    stack =[]
    for i in moves:
        for j in range(len(board)):
            tmp = board[j][i-1]
            board[j][i-1] = 0
            top = len(stack)
            if(tmp):
                chk = False
                if(top>0):
                    if(stack[top-1]==tmp):
                        stack.pop(len(stack)-1)
                        chk = True
                        answer+=2
                if(chk==False):stack.append(tmp)
                break
            
                   
    return answer