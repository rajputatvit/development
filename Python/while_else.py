i = 1

while i < 10:
    try:
        if i >= 1:
            raise
        
        if i == 12:
            break
    except Exception as e:
        pass
    i += 1
else:
    print 'else statement executed because break did not occur for while'