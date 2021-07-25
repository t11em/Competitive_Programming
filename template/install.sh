acc add --template cpp
acc config default-template cpp
acc config default-task-choice all
acc config default-test-dirname-format tests
rm -r `acc config-dir`/cpp
ln -snfv "$(pwd)/cpp" `acc config-dir`/cpp
