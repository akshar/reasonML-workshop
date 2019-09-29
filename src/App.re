[@react.component]
let make = () => {
  let headerView =
    <div className="p-2 mb-2"> <p> {React.string("Form Builder")} </p> </div>;

  let builderView =
    <div className="p-2 mb-6">
      <div className="mb-6">
        <input
          type_="text"
          className="outline-none bg-gray-200 p-2 w-full mb-2"
          placeholder="Enter short text title here..."
        />
        <a className="flex items-center justify-end text-xs" href="#">
          <img src=Icon.trashAlt className="w-2 h-2 inline-block mr-1" />
          <span> {React.string("Remove")} </span>
        </a>
      </div>
      <button
        className="bg-blue-200 hove:bg-blue-400 hover:text-white p-2 text-sm rounded">
        {React.string("Add short text")}
      </button>
    </div>;

  let previewView =
    <div className="p-2"> <p> {React.string("Preview")} </p> </div>;

  <div className="w-1/2 mx-auto"> headerView builderView previewView </div>;
};