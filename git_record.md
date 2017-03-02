##git add <file>：track file(把新增文件加入git的管理) or stage file(把已被git管理并且修改过的文件加入stage状态)
            
- git add <file>     <=>      git rm --cached <file>   track/untrack

- git add <file>     <=>      git reset HEAD <file> / git reset / git reset -- <file>  staged/unstage

##git commit <file>：1. commit staged file(把在stage区的文件提交)
      
- git commit <file>    <=>     git reset --soft HEAD^  修改后的文件保持不变，这次commit回退（文件处于stage area）

- git commit <file>    <=>     git reset HEAD^  修改后的文件保持不变，这次commit回退（文件处于unstage area）
                          
- git commit <file>    <=>     git reset --hard HEAD^  修改后的文件也回退到上一个commit，commit同时回退(删除整个commit，回到上一次状态)

##本地文件修改
                       
- file modifed                         <=>           git checkout -- <file>  文件的修改回退

##删除本地文件

- rm file                                   <=>           git checkout -- <file> / git checkout <file>

##merge（pull/merge）

- git pull / git merge (Conflict)           <=>                git reset --hard
