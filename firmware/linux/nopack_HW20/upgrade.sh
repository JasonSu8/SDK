#! /bin/sh
SCRIPT_DIR=$(cd `dirname $0`;pwd)

TARGET_DIR=$SCRIPT_DIR

die(){
    echo "ERROR:$@"	
    exit 255
}
# echo "`pwd`"

cd $TARGET_DIR

echo "`pwd`"

export LD_LIBRARY_PATH=./
./dmcam-cli -f TM-E2_HW20_SW154_20180828.bin







