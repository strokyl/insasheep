#!/usr/bin/env python

import sys

def usage():
    print("usage: %s <infile> <outfile>" % sys.argv[0])
    sys.exit(1)

def main():
    if (len(sys.argv) != 3):
        usage()

    infile = open(sys.argv[1], 'rb')
    data = infile.read()
    infile.close()

    outfile = open(sys.argv[2], 'wb')
    data = bytearray(data)
    for i in range(0, len(data), 2):
        data[i], data[i+1] = data[i+1], data[i]
    outfile.write(data)
    outfile.close()

if __name__ == '__main__':
    main()
