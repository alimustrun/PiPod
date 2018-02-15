#!/bin/sh
echo "Installing PiPod daemon"
cp scripts/run-script.sh /etc/init.d/launch-pipod
chmod 755 /etc/init.d/launch-pipod
update-rc.d launch-pipod defaults