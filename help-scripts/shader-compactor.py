import argparse
import re

def main():
    argparser = argparse.ArgumentParser()
    argparser.add_argument('file', type=str, help='The GLSL file to compact')

    args = argparser.parse_args()

    text = None
    with open(args.file, 'r') as f:
        text = f.read(-1)

    output = re.sub(r'\s*\n*\s*([;\{\}\(\)%-+=])\s*\n*\s*', r'\1', text)
    output = re.sub(r'\n{2,}', '\n', output)
    output = output.replace('\n', '\\n')
    
    print(output)

if __name__ == '__main__':
    main()