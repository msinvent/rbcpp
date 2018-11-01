from scripts.generator import Generator


class Msg(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'guard', 'header_name', 'ros_msg_type', 'ros_msg_name'])
        self.header_template_name = 'templates/msg_header.tmpl'
        self.impl_template_name = 'templates/impl_msg.tmpl'
        self.param_dict = params

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)


if __name__ == '__main__':
    d = {}
    d['class_name'] = 'Quaternion'
    d['ros_msg_type'] = 'geometry_msgs'
    d['ros_msg_name'] = 'Quaternion'

    message = Msg(d)
    message.create()