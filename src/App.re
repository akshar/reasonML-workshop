open Belt;
let se = React.string;
let a = xs => xs |> List.toArray |> React.array;
type shortText = {
  id: RandomId.t,
  title: string,
  answer: string,
};

type formItem =
  | ShorterText(shortText);

type action =
  | Add(formItem)
  | Update(formItem)
  | Delete(formItem);

let formId = formItem =>
  switch (formItem) {
  | ShorterText(shortText) => shortText.id
  };

let reducer = (state, action) =>
  switch (action) {
  | Add(formItem) => state @ [formItem]
  | Update(formItem) =>
    List.map(state, x =>
      RandomId.eq(x |> formId, formItem |> formId) ? formItem : x
    )
  | Delete(formItem) =>
    List.keep(state, x => !RandomId.eq(x |> formId, formItem |> formId))
  };

[@react.component]
let make = () => {
  let (state, disptach) = React.useReducer(reducer, []);

  let headerView =
    <div className="p-2 mb-2"> <p> {se("Form Builder")} </p> </div>;

  let builderView = {
    let shortTextView = shortText =>
      <div className="mb-6">
        <input
          type_="text"
          className="outline-none bg-gray-200 p-2 w-full mb-2"
          placeholder="Enter short text title here..."
        />
        <a
          className="flex items-center justify-end text-xs opacity-50 hover:opacity-100"
          href="#">
          <img src=Icon.trashAlt className="w-2 h-2 inline-block mr-1" />
          <span> {se("Remove")} </span>
        </a>
      </div>;

    let formItemView = formItem =>
      switch (formItem) {
      | ShorterText(shortText) => shortTextView(shortText)
      };

    let formItemsView = List.map(state, formItemView) |> a;

    <div className="p-2 mb-6">
      formItemsView
      <button
        onClick={_ =>
          disptach(
            Add(
              ShorterText({id: RandomId.generate(), title: "", answer: ""}),
            ),
          )
        }
        className="bg-blue-200 hove:bg-blue-400 hover:text-white p-2 text-sm rounded">
        {se("Add short text")}
      </button>
    </div>;
  };

  let previewView =
    <div className="p-2">
      <form>
        <div className="mb-6">
          <p className="text-lg"> {se("1.")} </p>
          <p className="mb-2"> {se("This is a short text title preview")} </p>
          <input
            type_="text"
            className="outline-none bg-gray-200 p-2 w-full mb-2"
            placeholder="Enter short text title here..."
          />
        </div>
        <button
          className="bg-green-200 hove:bg-green-400 hover:text-white p-2 text-sm rounded">
          {se("Add short text")}
        </button>
      </form>
    </div>;

  <div className="w-1/2 mx-auto"> headerView builderView previewView </div>;
};