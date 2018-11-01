from scripts.generator import Generator


class StdRBCMsg(Generator):
    def __init__(self, params: dict):
        super().__init__(['class_name', 'type', 'guard', 'header_name', 'ros_msg_type', 'ros_msg_name'])
        self.header_template_name = 'templates/header_std_msgs.tmpl'
        self.impl_template_name = 'templates/impl_std_msgs.tmpl'
        self.param_dict = params

    def create(self):
        print("Creating files for class {}".format(self.param_dict.get('class_name')))
        super().read(self.header_template_name, self.impl_template_name)
        super().write(self.param_dict)
