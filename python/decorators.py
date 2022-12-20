
# f je funkcia jednej premennej
def log(f):

    def f_ret(x):
        print(f.__name__,'called, argument',x)
        return f(x)

    return f_ret

@log
def square(x):
    return x*x

#square=log(square)

        
