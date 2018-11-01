from scripts.std_rbc_msg import StdRBCMsg

if __name__ == '__main__':
    d = {}
    d['class_name'] = 'UInt8Message'
    d['type'] = 'uint8_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'UInt8'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'UInt16Message'
    d['type'] = 'uint16_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'UInt16'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'UInt32Message'
    d['type'] = 'uint32_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'UInt32'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'UInt64Message'
    d['type'] = 'uint64_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'UInt64'

    message = StdRBCMsg(d)
    message.create()