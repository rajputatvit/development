import json
import os
import sys

data = {}
data['name'] = 'jitendra'

json_data = json.dumps(data)

filename = os.getcwd() + '\\' + 'json_data.json'


with open(filename, mode='w') as file_out:
    file_out.write(json_data)
    print 'json file saved: {0}'.format(filename)
    
print json_data

print 'End'