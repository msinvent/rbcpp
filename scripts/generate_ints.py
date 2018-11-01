from scripts.std_rbc_msg import StdRBCMsg

if __name__ == '__main__':
    d = {}
    d['class_name'] = 'Int8Message'
    d['type'] = 'int8_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'Int8'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'Int16Message'
    d['type'] = 'int16_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'Int16'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'Int32Message'
    d['type'] = 'int32_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'Int32'

    message = StdRBCMsg(d)
    message.create()

    d['class_name'] = 'Int64Message'
    d['type'] = 'int64_t'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'Int64'

    message = StdRBCMsg(d)
    message.create()