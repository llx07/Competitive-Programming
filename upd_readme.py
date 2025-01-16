import os

INDENT_SIZE = 4
s = ""

# 假设我们要遍历当前目录及其所有子目录
for dir, dirs, files in os.walk('./algo'):
    # 打印当前目录路径
    dirs.sort()
    files.sort()
    
    
    if dir.count('/') == 1:
        continue
    indent = " " * (dir.count('/')-2)*INDENT_SIZE
    
    s += f"{indent}- {dir[dir.rfind('/')+1:]}\n"
    for f in files:
        s += f"{' '*INDENT_SIZE}{indent}- {f[:f.rfind('.')]}\n"
    

content = open("README.md","r").read()


START_TAG = '<!-- AUTOSTART -->\n'
END_TAG = '<!--  AUTOEND  -->'

start_index = content.find(START_TAG) + len(START_TAG)
end_index = content.find(END_TAG)

old_s = content[start_index:end_index]

if old_s == s:
    exit(1)

new_content = content[:start_index] + s + content[end_index:]

with open("README.md","w") as f:
    f.write(new_content)