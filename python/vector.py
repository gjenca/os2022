class Vector(list):

    def __add__(self,other):

        ret=Vector()
        for x1,x2 in zip(self,other):
            ret.append(x1+x2)
        return ret

    def __repr__(self):
        
        return 'Vector({})'.format(list.__repr__(self))


