$ export ghname=<имя_пользователя>
$ export ghemail=<адрес_почтового_ящика>
$ export ghtoken=<сгенирированный_токен>
$ alias edit=nano

cd ${ghname}/workspace
$ source scripts/activate

$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${ghname}
  oauth_token: ${ghtoken}
  protocol: https
EOF
$ git config --global hub.protocol https
$ git init
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint:
hint:   git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint:   git branch -m <name>
Initialized empty Git repository in /home/klich26/klich26/workspace/projects/lab02/.git/

$ git remote add origin https://github.com/klich26/lab02.git
//config 
$ git config --list
user.name=klich26
user.email=dimus0007@gmail.com
hub.protocol=https
core.repositoryformatversion=0
core.filemode=true
core.bare=false
core.logallrefupdates=true
remote.origin.url=https://github.com/klich26/lab02.git
remote.origin.fetch=+refs/heads/*:refs/remotes/origin/*


$ git pull origin main
hint: Pulling without specifying how to reconcile divergent branches is
hint: discouraged. You can squelch this message by running one of the following
hint: commands sometime before your next pull:
hint:
hint:   git config pull.rebase false  # merge (the default strategy)
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint:
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 1.43 KiB | 86.00 KiB/s, done.
From https://github.com/klich26/lab02
 * branch            main       -> FETCH_HEAD
 * [new branch]      main       -> origin/main



$ touch README.md
$ git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

nothing added to commit but untracked files present (use "git add" to track)

$ git add README.md

$ git commit -m "added README.md"
[master 9e0f911] added README.md
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README.md


$ git push origin master
Username for 'https://github.com': klich26
Password for 'https://klich26@github.com':
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 278 bytes | 27.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'master' on GitHub by visiting:
remote:      https://github.com/klich26/lab02/pull/new/master
remote:
To https://github.com/klich26/lab02.git
 * [new branch]      master -> master

//с помощью git log можно посмотреть существующие commit
$ git log
commit 9e0f911416490de891aa362a0cb8ead21a18ff81 (HEAD -> master, origin/master)
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 20:37:41 2025 +0000

    added README.md

commit a453381b930fe488a0764b6e046bb5bdf6afb1fb (origin/main)
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 23:34:33 2025 +0300

    Initial commit

//pull после того как добавили .gitignore
$ git pull origin main
hint: Pulling without specifying how to reconcile divergent branches is
hint: discouraged. You can squelch this message by running one of the following
hint: commands sometime before your next pull:
hint:
hint:   git config pull.rebase false  # merge (the default strategy)
hint:   git config pull.rebase true   # rebase
hint:   git config pull.ff only       # fast-forward only
hint:
hint: You can replace "git config" with "git config --global" to set a default
hint: preference for all repositories. You can also pass --rebase, --no-rebase,
hint: or --ff-only on the command line to override the configured default per
hint: invocation.
remote: Enumerating objects: 6, done.
remote: Counting objects: 100% (6/6), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 4 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (4/4), 1.81 KiB | 88.00 KiB/s, done.
From https://github.com/klich26/lab02
 * branch            main       -> FETCH_HEAD
   a453381..cb5ec0f  main       -> origin/main
Updating 9e0f911..cb5ec0f
Fast-forward
 .gitignore | 4 ++++
 1 file changed, 4 insertions(+)
 create mode 100644 .gitignore


//после push commit с README.md на github появилось 2 ветки с помощью pull request можно перенести из добавленной 
ветки в основную а добавленную удалить 
$ git log
commit cb5ec0f5a34db5095a3b86c093dd627892b02112 (HEAD -> master, origin/main)
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 23:44:40 2025 +0300

    Create .gitignore

commit 9f530a4de12b05ba417c529e1258b6c14187d179
Merge: a453381 9e0f911
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 23:41:49 2025 +0300

    Merge pull request #1 from klich26/master

    added README.md

commit 9e0f911416490de891aa362a0cb8ead21a18ff81 (origin/master)
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 20:37:41 2025 +0000

    added README.md

commit a453381b930fe488a0764b6e046bb5bdf6afb1fb
Author: klich26 <dimus0007@gmail.com>
Date:   Mon Mar 17 23:34:33 2025 +0300

    Initial commit



$ mkdir sources
$ mkdir include
$ mkdir examples




$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF





$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF


$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF

$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF

 $ git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        examples/
        include/
        sources/

nothing added to commit but untracked files present (use "git add" to track)


$git add .
$git commit -m "added sources "
[master 07fa9a3] added sources
 4 files changed, 32 insertions(+)
 create mode 100644 examples/example1.cpp
 create mode 100644 examples/example2.cpp
 create mode 100644 include/print.hpp
 create mode 100644 sources/print.cpp

$ git push origin master
Username for 'https://github.com': klich26
Password for 'https://klich26@github.com':
Enumerating objects: 10, done.
Counting objects: 100% (10/10), done.
Compressing objects: 100% (7/7), done.
Writing objects: 100% (9/9), 959 bytes | 36.00 KiB/s, done.
Total 9 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'master' on GitHub by visiting:
remote:      https://github.com/klich26/lab02/pull/new/master
remote:
To https://github.com/klich26/lab02.git
 * [new branch]      master -> master
