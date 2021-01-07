""" Stack """

class Stack:
    """ implementation of of a stack """
    def __init__(self):
        """ inits """
        self.items = []
    
    def __str__(self):
        """ overloads print """
        stackAsString = '<Queue>: ['
        if len(self.items) == 0:
            return ''
        elif len(self.items) == 1:
            return self.items[0]
        for item in self.items:
            stackAsString += str(item) + ', '
        return stackAsString[:-2] + "]"
    
    def define(self, items):
        """ defines stack 
        - items must be a list
        """
        if items is list:
            self.items = items
        else:
            raise ValueError("Not a list")
    
    def push(self, item):
        """ c-like push """
        self.items.append(item)
    
    def pop(self):
        """ pop from queue """
        if len(self.items) == 0:
            raise Exception("The list is empty")
        return self.items.pop()
    
    def peek(self):
        """ looks at first element in queue """
        if len(self.items) == 0:
            raise Exception("The list is empty")
        return self.items[len(self.items)-1] 
    
    def isEmpty(self):
        """ checks to see if it is empty """
        return self.items == []
    
    def size(self):
        """ looks at length/size queue """
        return len(self.items)
    
    def show(self):
        """ prints entire queue """
        print(self.items)
    
    def clear(self):
        """ clears entire queue """
        self.items = []  
