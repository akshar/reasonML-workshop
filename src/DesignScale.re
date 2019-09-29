[@react.component]
let make = () =>
  <div
    className="w-screen h-screen flex justify-center align-center items-center">
    <div className="md:flex p-6 bg-purple-200 rounded-lg shadow-lg">
      <img
        className="h-16 w-16 md:h-24 md:w-24 rounded-full mx-auto md:mx-0 md:mr-6"
        src=Image.avatar0
      />
      <div className="font-mono text-center md:text-left">
        <h2 className="text-lg"> {React.string("foo")} </h2>
        <div>
          <div className="text-purple-500">
            {React.string("Software dev")}
          </div>
          <div className="text-gray-600">
            {React.string("hello@example.com")}
          </div>
          <div className="text-gray-600">
            {React.string("(91) 01234 56899")}
          </div>
        </div>
      </div>
    </div>
  </div>;