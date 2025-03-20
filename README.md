# Snake
add - stages changes (which changes are commited, git add <file> for specific or git add . for all changes)
commit - save changes to local repository
commit -m - gives a message to each save
push - sends changes to GitHub
push -u - dont specify the branch everytime, after usign git push -u origin mater once, you can just use git push after
pull - gets the files for GitHub to the local repository
clone - clones a repository from github
difference clone and pull: clone copies a repository (like a first time setup) while pull updates an existing local repository
status - checks repository status (view untracked files)
log - commit history
diff HEAD - compare the current state withe the last commit
diff commit1 commit2 - compare 2 commits, commit1 and commit2 are the commit's names

HOW IT WORKS: 
collisions: walls and itself
every apple eaten equals +1length in the back
every 5-10 apples => speed up
if length == grid size => WIN
move w a s d
some kind of tickrate and movement fundamentals
if w pressed move up
somehow keep moving up
turn off opposite movement(cant go w s or a d)
random apple placement -places occupied by the snake
score
Start/Pause/Restart
Leaderboards
