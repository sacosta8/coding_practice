#Little random script that utilizes passing functions into other functions in Python. Got the idea after learning the concept from my CS480w class where javascript does stuff like this all the time
def func1(a,b,c):
    return (func1,a*b,b*c,a*c)

def otherFunc(aFunction,d,e,f):
    return aFunction(d,e,f)[1:]

def func2(a,b,c):
    return (func2,a/b,b/c,a/c)

class Stack:
    def __init__(self):
        self.elements = []
    def push(self,value):
        self.elements.append(value)
    def pop(self):
        if len(self.elements) > 0:
            return self.elements.pop()

class Queue:
    def __init__(self):
        self.elements = []
    def push(self,value):
        self.elements.insert(0,value)
    def pop(self):
        if len(self.elements) > 0:
            return self.elements.pop()

def recursiveFunction(numbers,funcStack):
    while len(funcStack.elements) > 0:
        numbers = recursiveFunction( otherFunc( funcStack.pop(),(*numbers) ) ,funcStack)
    return numbers

funcStack = Stack()
numbers = (1,2,3)
print('\nbeginning numbers: ' + str(numbers) + '\n')
funcStack.push(func1)
funcStack.push(func2)
print("\nUsing a stack to call func2 then func1\n______________________________\n")
[print(otherFunc(funcStack.pop(),*numbers)) for i in range(0,len(funcStack.elements))]
print('\n')
print("Using a queue to call func1 then func2\n______________________________\n")
funcQueue = Queue()
funcQueue.push(func1)
funcQueue.push(func2)
[print(otherFunc(funcQueue.pop(),*numbers)) for i in range(0,len(funcQueue.elements))]
print('\n')
funcStack.push(func1)
funcStack.push(func2)
print('\nEnd result of using recursion to modify the numbers using both func1 and func2\n______________________________\n')
print(recursiveFunction(numbers,funcStack))
print('\n')
