[@react.component]
let make = () =>
  <div>
    <img className="h-16 w-16 md:h-24 md:w-24" src=Image.avatar0 />
    <div>
      <h2> {React.string("foo")} </h2>
      <div>
        <div> {React.string("Software dev")} </div>
        <div> {React.string("hello@example.com")} </div>
        <div> {React.string("(91) 01234 56899")} </div>
      </div>
    </div>
  </div>;