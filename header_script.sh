 #!/bin/bash

for i in *.c *.h *.cpp #or *.h # or whatever other pattern...
do
  if ! grep -q Copyright $i
  then
    cat License_header_1011 $i >$i.new && mv $i.new $i
  fi
done
