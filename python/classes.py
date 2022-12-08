"""Modul pre geometrické útvary
"""
class Obdlznik:
    """Popis toho, čo je obdĺžnik
    """    

    def __init__(self,a,b):
        
        self.a=a
        self.b=b


    def plocha(self):
        
        return self.a*self.b

class Stvorec(Obdlznik):

    def __init__(self,n):

        self.a=n
        self.b=n
