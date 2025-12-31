import turtle as tt

def rose():
    tt.color('red')
    for i in range(270):
        tt.fd(i)
        tt.left(70)
    tt.done()
rose()