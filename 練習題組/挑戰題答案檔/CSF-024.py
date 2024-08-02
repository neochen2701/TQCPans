class BrowserHistory:
    def __init__(self):
        self.stack_back = []
        self.stack_forward = []
        self.current_page = ""
        self.full_history = []

    def visit(self, url):
        if self.current_page:
            self.stack_back.append(self.current_page)
        self.current_page = url
        self.stack_forward = []
        self.full_history.append(self.current_page)

    def back(self):
        if not self.stack_back:
            return
        self.stack_forward.append(self.current_page)
        self.current_page = self.stack_back.pop()
        self.full_history.append(self.current_page)

    def forward(self):
        if not self.stack_forward:
            return
        self.stack_back.append(self.current_page)
        self.current_page = self.stack_forward.pop()
        self.full_history.append(self.current_page)

    def current(self):
        print(self.current_page)

    def history(self):
        print(" -> ".join(self.full_history))


N = int(input())
browser = BrowserHistory()

for _ in range(N):
    command = input().split()
    if command[0] == "visit":
        browser.visit(command[1])
    elif command[0] == "back":
        browser.back()
    elif command[0] == "forward":
        browser.forward()

browser.current()
browser.history()
