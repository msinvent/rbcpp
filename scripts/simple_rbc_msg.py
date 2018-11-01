from scripts.generator import Generator


class SimpleRBCMsg(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'inher', 'guard', 'header_name', 'ros_msg_type', 'ros_msg_name'])
        self.header_template_name = 'templates/header_simple.tmpl'
        self.impl_template_name = 'templates/impl_simple.tmpl'
        self.param_dict = params

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)


if __name__ == '__main__':
    d = {}
    d['class_name'] = 'ServiceMessage'
    d['inher'] = 'final'
    d['ros_msg_type'] = 'std_msgs'
    d['ros_msg_name'] = 'ColorRGBA'

    message = SimpleRBCMsg(d)
    message.create()