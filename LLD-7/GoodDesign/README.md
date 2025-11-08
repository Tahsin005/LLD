# SOLID Design Priciples

---

<img src="https://github.com/Tahsin005/solid-design-priciples-cpp-implementation/blob/main/standardUml.png">

### **1. Single Responsibility Principle (SRP)**

**Definition:** A class should have only one reason to change; it should do one thing only.

**How the code follows SRP:**

* `TextElement`, `ImageElement`, `NewLineElement`, `TabSpaceElement` → **each class represents a single type of document element**. They are only responsible for rendering themselves.
* `Document` → **responsible only for holding document elements**, not rendering or saving.
* `DocumentRenderer` → **responsible only for rendering the document**, not editing or saving it.
* `DocumentEditor` → **manages user interaction and document modification**, but doesn’t handle persistence directly.
* `FileStorage` and `DBStorage` → **responsible only for saving data**, not editing or rendering.

 **SRP is followed well. Each class has one clear responsibility.**

---

### **2. Open/Closed Principle (OCP)**

**Definition:** Classes should be open for extension but closed for modification.

**How the code follows OCP:**

* `DocumentElement` is an **abstract base class**. You can create new elements like `VideoElement`, `AudioElement`, or `TableElement` without changing existing code.
* `Persistence` is an **interface/abstract class**, allowing you to add new storage types like `CloudStorage` without modifying `FileStorage` or `DBStorage`.
* `DocumentRenderer` can render any new `DocumentElement` because it just calls `render()` polymorphically.

 **OCP is followed through abstraction and polymorphism.**

---

### **3. Liskov Substitution Principle (LSP)**

**Definition:** Subtypes must be substitutable for their base types without affecting correctness.

**How the code follows LSP:**

* `TextElement`, `ImageElement`, `NewLineElement`, `TabSpaceElement` → all inherit from `DocumentElement` and implement `render()`.
  → You can replace any `DocumentElement*` in `Document` with another derived type, and `DocumentRenderer` will still work correctly.
* `FileStorage` and `DBStorage` → both inherit `Persistence` and can be used interchangeably in `DocumentEditor`.

 **LSP is followed; derived classes behave correctly through the base interface.**

---

### **4. Interface Segregation Principle (ISP)**

**Definition:** Clients should not be forced to depend on interfaces they do not use.

**How the code follows ISP:**

* `DocumentElement` has only the `render()` method → **minimal and specific interface**.
* `Persistence` has only `save()` → editor classes don’t need to know how storage works internally.
* `DocumentEditor` interacts only with `Document` and `Persistence`, without knowing their internals.

 **ISP is followed; no class is forced to implement methods it doesn’t need.**

---

### **5. Dependency Inversion Principle (DIP)**

**Definition:** High-level modules should not depend on low-level modules; both should depend on abstractions.

**How the code follows DIP:**

* `DocumentEditor` (high-level module) depends on `Persistence` (abstraction), not directly on `FileStorage` or `DBStorage` (low-level modules).
* You can pass in any storage type to `DocumentEditor` without modifying it.
* `DocumentRenderer` depends on `Document` abstraction, not on specific element types.

 **DIP is followed; dependencies are inverted using interfaces/abstract classes.**

---

### **Summary Table:**

| Principle | How the Code Complies                                                     |
| --------- | -------------------------------------------------------------------------- |
| SRP       | Each class has a single, clear responsibility.                             |
| OCP       | New elements or storage types can be added without changing existing code. |
| LSP       | Derived classes can be substituted for base types safely.                  |
| ISP       | Interfaces are minimal; clients only use what they need.                   |
| DIP       | High-level modules depend on abstractions, not concrete classes.           |

